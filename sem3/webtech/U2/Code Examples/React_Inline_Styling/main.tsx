// src/main.jsx
import React from "react";
import ReactDOM from "react-dom/client";

function InlineStyled() {
  return (
    <div>
      <h1 style={{ color: "blue", fontSize: "24px" }}>
        Hello with Inline Style
      </h1>
      <p style={{ backgroundColor: "lightyellow", padding: "10px" }}>
        This paragraph is styled using inline CSS in JSX.
      </p>
    </div>
  );
}

ReactDOM.createRoot(document.getElementById("root")).render(
  <InlineStyled />
);
