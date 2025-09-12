// Show date and time
function updateDateTime() {
    var now = new Date();
    document.getElementById('datetime').textContent = now.toLocaleString();
}
setInterval(updateDateTime, 1000);
updateDateTime();

var form = document.getElementById('registrationForm');
form.addEventListener('submit', function(e) {
    var name = document.getElementById('name').value.trim();
    var email = document.getElementById('email').value.trim();
    var phone = document.getElementById('phone').value.trim();
    var age = document.getElementById('age').value.trim();
    var tshirt = document.getElementById('tshirt').value;
    var valid = true;

    // Clear errors
    document.getElementById('nameError').textContent = "";
    document.getElementById('emailError').textContent = "";
    document.getElementById('phoneError').textContent = "";
    document.getElementById('ageError').textContent = "";
    document.getElementById('tshirtError').textContent = "";

    // Name check
    if(name === "") {
        document.getElementById('nameError').textContent = "Please enter your name";
        valid = false;
    }
    // Email check (very basic)
    if(email === "" || email.indexOf('@') === -1) {
        document.getElementById('emailError').textContent = "Enter a valid email";
        valid = false;
    }
    // Phone check (just length)
    if(phone.length !== 10 || isNaN(phone)) {
        document.getElementById('phoneError').textContent = "Enter 10 digit phone number";
        valid = false;
    }
    // Age check
    if(age === "" || isNaN(age) || age < 5 || age > 100) {
        document.getElementById('ageError').textContent = "Enter valid age (5-100)";
        valid = false;
    }
    // T-shirt size check
    if(tshirt === "") {
        document.getElementById('tshirtError').textContent = "Select a size";
        valid = false;
    }
    if(!valid) {
        e.preventDefault();
        alert("Please fill all required fields!");
    }
});