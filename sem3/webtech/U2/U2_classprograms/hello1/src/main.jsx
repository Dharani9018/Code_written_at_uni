import { createRoot } from 'react-dom/client'
import './index.css'; // import css file 
/*
const name = "Ajay"
const element = (
<>
<h2>Hello,{name} This is sample program1</h2>
<p>2+6 ={2+6}</p>
</>)


createRoot(document.getElementById("root"))
.render(element)

function Element(){
    const name = "Ajay";
    const sem = 3;
    const subj = "Web Technologies";

  return(
    <>
    <h2>Student Information</h2>
    <p>Name : {name}</p>
    <p>Semester : {sem}</p>
    <p>Subject : {subj}</p>
    </>

  )
}

createRoot(document.getElementById("root")).render(<Element/>)

function Welcome(props){
  return <h1>Hello,{props.name}...Lets kickstart with Maaya 2025 </h1>
}

createRoot(document.getElementById("root")).render(<Welcome name = "PESU"/>)

function InlineStyle(){

  return(
    <>
    <h1 style = {{color:"blueviolet",fontSize:"24px"}}>This is inline style in react</h1>
    <p style={{backgroundColor:"yellowgreen",padding:"10px"}}>Styling in JSX-inline </p>
    </>
  )
}
createRoot(document.getElementById("root")).render(<InlineStyle/>)*/

function InternalStyle(){
  return(
    <>
    <h1 className='heading'>This is internal style in react</h1>
    <p className='para'>Styling in JSX-internal </p>
    </>
  )
}
createRoot(document.getElementById("root")).render(<InternalStyle/>)