# Forms

## Form Tag Attributes

1. **`method`**
    - How form data is sent to the server.
    - **`get`**: Data is added to the URL (visible, for non-sensitive info).
    - **`post`**: Data is sent in the request body (hidden, for sensitive or large data).

2. **`action`**
    - URL where form data goes after submission.
    - If not set, submits to the same page.

3. **`target`**
    - Where to show the response after submitting.
    - **`_self`**: Same tab (default).
    - **`_blank`**: New tab.
    - **`_parent`**: Parent frame.
    - **`_top`**: Full window.

4. **`name`**
    - Used in form elements (like `<input>`, `<select>`, `<textarea>`) to identify the data sent to the server.

## Label Element

- The `<label>` element adds a caption for a form item.
- It connects text to an input element.
- The `for` attribute links the label to an input by matching the input's `id`.
- Example:
    ```html
    <label for="username">Username:</label>
    <input type="text" id="username" name="username">
        ```

## Checkboxes

- Used to collect multiple choice input.
- Every checkbox needs a `value` attribute, which is sent with the form data if the box is checked.
- If a checkbox is not checked, it does not contribute any value to the form data.
- By default, no checkbox is checked. To make a checkbox checked by default, add the `checked` attribute.

Example:
```html
<input type="checkbox" name="hobby" value="reading"> Reading
<input type="checkbox" name="hobby" value="sports"> Sports
<input type="checkbox" name="hobby" value="music" checked> Music
```

## Menus (Select Dropdowns)

- Created with `<select>` tags.
- There are two kinds:
        - Menus that behave like radio buttons (default, only one can be selected)
        - Menus that behave like checkboxes (multiple selections allowed, use `multiple` attribute)
- The `name` attribute is required.
- The `size` attribute sets how many items are visible (default is 1).
- If `size` > 1 or `multiple` is set, the menu appears as a list box.

Each menu item is an `<option>`. To preselect an item, use the `selected` attribute.

Example (single select):
```html
<form action="">
    <p>
        With size = 1 (the default)
        <select name="groceries"> 
            <option>milk</option>
            <option>bread</option>
            <option>eggs</option>
            <option>cheese</option>
        </select>
    </p>
</form>
```

Example (multiple select):
```html
<select name="groceries" multiple size="3">
    <option>milk</option>
    <option>bread</option>
    <option>eggs</option>
    <option>cheese</option>
</select>
```

## Reset and Submit Buttons

- Both are created with `<input>`:
```html
<input type="reset" value="Reset Form">
<input type="submit" value="Submit Form">
```
- The submit button encodes the form data and sends it to the server (to the URL in the `action` attribute).
- Every form should have a submit button.

## HTML5 – New Input Widgets

HTML5 introduced new input types for better user experience and validation:

- `email`: for email addresses (auto-validates format)
- `number`: spinbox for numbers
- `range`: slider for numeric range
- `url`: for web addresses
- `color`: color picker
- `search`: search box
- `date`: date picker
- `month`: month picker
- `time`: time picker
- `week`: week picker
- `datetime-local`: date and time picker

Example (email):
```html
E-mail: <input type="email" name="user_email" />
```
The value of the email field is automatically validated when the form is submitted.

