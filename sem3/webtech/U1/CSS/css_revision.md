# CSS Levels Revision Sheet

## 1. External CSS
- Defined in a separate `.css` file (e.g., `mystyle.css`).
- Linked in HTML with `<link rel="stylesheet" href="mystyle.css">`.
- Good for reusing styles across multiple pages.

## 2. Internal CSS
- Defined inside a `<style>` tag in the `<head>` section of HTML.
- Affects only the current HTML page.
- Example:
```html
<style>
  p { color: green; }
</style>
```

## 3. Inline CSS
- Written directly in the HTML element using the `style` attribute or a class with `!important`.
- Highest priority.
- Example:
```html
<p style="color: red;">This is inline styled</p>
```

---

## CSS Specificity & Priority
- Inline > Internal > External
- `!important` overrides all other styles for that property.

---

## Quick Table
| Method      | Where defined         | Example                              | Priority |
|-------------|----------------------|--------------------------------------|----------|
| Inline      | In element           | `<p style="color:red">`             | 1        |
| Internal    | `<style>` in `<head>`| `<style>p{color:green}</style>`      | 2        |
| External    | `.css` file          | `mystyle.css`                        | 3        |

---

## Practice Questions
1. Which CSS method is best for styling multiple pages?
2. How do you override an external style with an internal style?
3. What does `!important` do?
4. Write an example of each CSS level.

---

## Tips to Remember
- Use the mnemonic: "I Inherit Everything" (Inline > Internal > External).

---

## What does !important do in CSS?

The `!important` declaration in CSS is used to give a particular style rule the highest priority. When you add `!important` to a CSS property, it overrides any other declarations for that property, even if those declarations have higher specificity or come later in the stylesheet. This is useful when you want to ensure that a specific style is always applied, regardless of other conflicting rules.

However, overusing `!important` can make your CSS harder to maintain and debug, so it should be used sparingly and only when necessary. For example, in the code:

```css
.inline-style {
  color: rgb(255, 133, 133) !important;
}
```
The color defined for the `.inline-style` class will always take precedence over other color rules for that element.
# CSS Selectors

## What is a CSS Selector?
A CSS selector is a pattern that matches HTML elements for styling. Selectors allow you to apply CSS rules to specific parts of your HTML document.

### Common Selector Types:
- **Element Selector:** Targets all elements of a type (e.g., `h2`).
- **Class Selector:** Targets elements with a specific class (e.g., `.third`).
- **ID Selector:** Targets a unique element with a specific id (e.g., `#first`).
- **Descendant Selector:** Targets elements inside another element (e.g., `ul a`).
- **Child Selector:** Targets direct children (e.g., `.items > a`).
- **Group Selector:** Applies the same style to multiple selectors (e.g., `h2, p, div`).

## Example Program Overview

The provided HTML demonstrates:
- Styling by id (`#first`, `#second`)
- Styling by class (`.third`, `.fourth`)
- Styling by element (`h2`)
- Combining selectors for specificity (`div.fourth`, `.items > a`, `ul a`)
- Grouping selectors (`h2, p, div`)
- Inline styles (using the `style` attribute)
- Internal styles (using the `<style>` tag in `<head>`)

### Key Takeaways:
- Selector specificity determines which style is applied if multiple rules match.
- Inline styles override internal and external styles.
- Grouping and combining selectors helps reduce repetition and increase specificity.

## Gotchas:
- More specific selectors (like id) override less specific ones (like class or element).
- Inline styles have the highest priority.
- Child selectors (`>`) only match direct children, not all descendants.
