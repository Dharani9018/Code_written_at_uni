// src/main.jsx
import React from "react";
import ReactDOM from "react-dom/client";

const element = (
  <div>
    <h1>Hello, JSX!</h1>
    <p>2 + 2 = {2 + 2}</p>
  </div>
);

ReactDOM.createRoot(document.getElementById("root")).render(element);

