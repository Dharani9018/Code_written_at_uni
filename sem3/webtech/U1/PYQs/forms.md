**1. Create a Placement form with the following controls:
a. A text box to collect the student’s name and SRN
b. A multiline input field to collect college name and address
c. A student should give choice to tick their department from a list
of departments
i. CSE
ii. ECE
iii. MECH
d. A collection of three radio buttons for Semester option that are
labelled as follows:
i. IV
ii. V
iii.VI
e. Submit and reset Button**
```html
    <!DOCTYPE html>
<html>
    <head>
        <title>Forms</title>
    </head>

<body>
    <form method="get" action="#" target="_blank">
        <fieldset>
            <legend>Name and SRN</legend>
            <label for="name">Name: </label>
            <input type="text" id="name" name="name" maxlength="25" required />
            <br><br>
            <label for="srn">SRN:</label>
            <input type="text" id="srn" name="srn" required />
        </fieldset>
        <br><br>
        <fieldset>
            <legend>College Name and Address</legend>
            <textarea id="college" name="college" rows="2" cols="30" placeholder="College Name"></textarea>
            <br><br>
            <textarea id="address" name="address" rows="3" cols="30" placeholder="Address"></textarea>
        </fieldset>
        <br><br>
        <fieldset>
            <legend>Department</legend>
            <label><input type="checkbox" name="department" value="CSE">CSE</label>
            <label><input type="checkbox" name="department" value="ECE">ECE</label>
            <label><input type="checkbox" name="department" value="MECH">MECH</label>
        </fieldset>
        <br><br>
        <fieldset>
            <legend>Semester</legend>
            <label><input type="radio" name="semester" value="IV">IV</label>
            <label><input type="radio" name="semester" value="V">V</label>
            <label><input type="radio" name="semester" value="VI">VI</label>
        </fieldset>
        <br><br>
        <input type="submit" value="Submit">
        <input type="reset" value="Reset">
    </form>
</body>
</html>
```
