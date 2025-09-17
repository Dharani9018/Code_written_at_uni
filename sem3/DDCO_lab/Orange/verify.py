import random
import subprocess

# Simulation parameters
NUM_SEQUENCES = 10      # number of random sequences
MAX_COINS = 6           # max coins in a sequence
COINS = [0, 5, 10]      # allowed coin values

def expected_behavior(sequence):
    """
    Compute expected dispense outputs for a sequence of coins.
    Carry is handled: e.g. 10+10=20 => dispense once, carry 5.
    """
    state = 0
    outputs = []
    for coin in sequence:
        state += coin
        if state >= 15:
            outputs.append(1)
            state -= 15
        else:
            outputs.append(0)
    return outputs

def run_verilog_test(sequence):
    """
    Run Verilog simulation with a given coin sequence.
    Uses defines to pass coin sequence into Verilog testbench.
    """
    # Convert sequence to bit-encoding: 01=₹5, 10=₹10, 00=no coin
    seq_bits = []
    for coin in sequence:
        if coin == 5:
            seq_bits.append("01")
        elif coin == 10:
            seq_bits.append("10")
        else:
            seq_bits.append("00")

    # Write sequence file for testbench
    with open("sequence.txt", "w") as f:
        f.write(" ".join(seq_bits))

    # Compile and run simulation
    subprocess.run(["iverilog", "-o", "test", "Vending_machine.v", "testbench.v"])
    result = subprocess.run(["vvp", "vending_tb"], capture_output=True, text=True)

    # Parse $monitor output lines
    dispense_out = []
    for line in result.stdout.splitlines():
        if "Coin=" in line:
            parts = line.strip().split("|")
            coin_str = parts[1].split("=")[1].strip()
            dispense = int(parts[2].split("=")[1].strip())
            dispense_out.append(dispense)

    return dispense_out

def main():
    mismatches = []

    for i in range(NUM_SEQUENCES):
        seq = [random.choice(COINS) for _ in range(MAX_COINS)]
        expected = expected_behavior(seq)
        actual = run_verilog_test(seq)

        # Truncate to match lengths
        length = min(len(expected), len(actual))
        expected, actual = expected[:length], actual[:length]

        if expected != actual:
            mismatches.append((seq, expected, actual))

    print("Simulation finished.")
    if mismatches:
        print("Mismatches found:")
        for seq, exp, act in mismatches:
            print(f"  Sequence: {seq}")
            print(f"  Expected: {exp}")
            print(f"  Actual:   {act}")
    else:
        print("All sequences matched expected behavior!")

if __name__ == "__main__":
    main()

