# Java Script:
## Formal name : ECMAScript.
## Earlier Name : LiveScript.
##  Basic version of ecma script.
## Scripting Language: Server side and client side.
## Creates Dynamic and interactive web content
## Manipulates webpages, responf to user actions -Clicks and keystrokes -> communication with the server.
## Tiobe index - 6th.
## Web Browser:
`console.log() - developer options -> console`
>Many way to embed the script into html:
>> 1. `<script> Java script statement </script>`
>> 2. `program1.js ->call this in the html`
# Variables:
## Container for storing data.
`let`,`const`,`var`.
`let`/`var` -> values can change.
# Data types:
### String - Single or double quotes
### NUmber - integer,decimals.
`let a =10;`
`let b = "Pes"`
### Boolean - `true` or `false`.
### Array: heterogeneous -> can store elements of different datatypes.
```javascript
//Ex1
const name = "PESU"
let age = 30
const price = 19.4
let isStudent = true;

Object:
const person = {
    firstname:"James",
    lastname: "Bond"
};
```
```javascript
//Ex2:
Arrays: (a list of items)
const colors = ["red","green","blue"];
document.writeln(colors[1]); //index starts from 0.

const mixed = [25,"pesu",true,{class: A&C}]
```

# Java Script:
## Formal name : ECMAScript.
## Earlier Name : LiveScript.
##  Basic version of ecma script.
## Scripting Language: Server side and client side.
## Creates Dynamic and interactive web content
## Web Browser:
`console.log() - developer options -> console`
>Many way to embed the script into html:
>> 1. `<script> Java script statement </script>`
>> 2. `program1.js ->call this in the html`
# Variables:
## Container for storing data.
`let`,`const`,`var`.
`let`/`var` -> values can change.
# Data types:
### String - Single or double quotes
### NUmber - integer,decimals.
`let a =10;`
`let b = "Pes"`
### Boolean - `true` or `false`.
### Array: heterogeneous -> can store elements of different datatypes.
```javascript
//Ex1
const name = "PESU"
let age = 30
const price = 19.4
let isStudent = true;

Object:
const person = {
    firstname:"James",
    lastname: "Bond"
};
```
```javascript
//Ex2:
Arrays: (a list of items)
const colors = ["red","green","blue"];
document.writeln(colors[1]); //index starts from 0.

const mixed = [25,"pesu",true,{class: A&C}]
```
## `this` keyword:
> A special keyword whose depends on how a function is called, not where its written.(Its like an object that is currently using the function).
Absolutely, Dharani! Here's a clean and structured summary of everything we've discussed so far—perfect for your notes:

---

## 🧠 JavaScript Execution & Runtime Concepts

### 1. **Global Object**
- When JavaScript starts, it creates a single **global object**.
- In browsers, this is the `window` object.
- All global variables and functions become properties of `window`.
  
```javascript
  window.status = "test";
  status = "test"; // Same effect
```

---

### 2. **Browser as a Runtime**
- A **browser** is a software that loads and renders web pages.
- It contains a **JavaScript engine** (like V8 in Chrome) that interprets and executes JS code.
- Unlike C (which compiles to `.exe`), JavaScript is **interpreted and executed directly** by the browser.

---

### 3. **JavaScript Execution Flow**
- JavaScript is **not precompiled** like C.
- Instead, it goes through:
  1. **Parsing**: Code is broken into tokens and converted into an **Abstract Syntax Tree (AST)**.
  2. **Interpretation**: Code is executed line-by-line.
  3. **JIT Compilation**: Frequently-used code is compiled into machine code for speed.

---

### 4. **Abstract Syntax Tree (AST)**
- AST is a tree-like structure representing the syntax of your code.
- Helps the engine understand and optimize code.
  ```javascript
  let x = 5 + 3;
  ```
  Simplified AST:
  ```
  VariableDeclaration
   └─ VariableDeclarator
       ├─ Identifier (x)
       └─ BinaryExpression
           ├─ Literal (5)
           └─ Literal (3)
  ```

---

### 5. **Just-In-Time (JIT) Compilation**
- JIT compiles **hot paths**—code that runs frequently.
- Everything starts interpreted, but repetitive code is compiled for performance.
- This hybrid model balances **fast startup** and **optimized execution**.

---

### 6. **API (Application Programming Interface)**
- APIs allow software systems to communicate.
- Like a waiter between you (client) and the kitchen (server).
- Used for tasks like fetching data, logging in, or accessing services.
- Common types: **REST**, **SOAP**, **GraphQL**.
---
---

## 🪟 `window` Object in JavaScript

### 🔹 What is `window`?
- In **client-side JavaScript**, the `window` object is the **global object**.
- It represents the **browser window/tab** where your web page runs.
- All global variables, functions, and built-in browser features are properties of `window`.

---

### 🔹 Key Properties & Behavior
- When JavaScript starts, it creates a single global object—`window` in browsers.
- Any variable or function declared in the global scope becomes a property of `window`.
  ```javascript
  var x = 10;
  window.x === x; // true
  ```

- You can access global properties **with or without** the `window.` prefix:
  ```javascript
  window.status = "test";
  status = "test"; // same effect
  ```

- `window` is an instance of the built-in `Window` constructor.

---

### 🔹 What Lives Inside `window`?
| Property/Method       | Description                                 |
|-----------------------|---------------------------------------------|
| `window.document`     | Represents the HTML page (DOM)              |
| `window.location`     | Info about the current URL                  |
| `window.alert()`      | Shows a popup message                       |
| `window.setTimeout()` | Runs code after a delay                     |
| `window.myVar`        | Your global variable `myVar`                |

---

### 🔹 Why It Matters
- `window` is the **central hub** for interacting with the browser.
- It gives access to both your code and browser APIs.
- Understanding `window` helps you avoid global scope pollution and write cleaner code.

---


