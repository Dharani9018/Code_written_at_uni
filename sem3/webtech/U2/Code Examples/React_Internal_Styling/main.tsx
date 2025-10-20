import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css"; // Import CSS file

function InternalStyled() {
  return (
    <div>
      <h1 className="heading">Hello with Internal CSS</h1>
      <p className="paragraph">
        This paragraph is styled using an external CSS file.
      </p>
    </div>
  );
}

ReactDOM.createRoot(document.getElementById("root")).render(
  <InternalStyled />
);
