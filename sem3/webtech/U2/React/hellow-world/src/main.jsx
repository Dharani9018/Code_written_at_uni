import { createRoot } from 'react-dom/client'
/*
//Child component
function ChildComponent({name,college})
{
  return(
    <div>
      <h2>Name: {name}</h2>
      <h2>College: {college}</h2>
    </div>
  )
}

//parent component
function ParentComponent()
{
  return(
    <div>
      <ChildComponent name = "Ajay" college = "PESU"/>
    </div>
  )
}
createRoot(document.getElementById('root')).render(<ParentComponent/>)
*/

/*
function ResImage({src1})
{
  return(
    <div>
      <img src={src1} />
    </div>
  )
}

function ResCaption()
{
  return(
    <div>
      <p>This is a random image from Unsplash</p>
    </div>
  )
}

function Link()
{
  return(
    <div>
      <a href="https://unsplash.com/" target="_blank">Link to Unsplash</a>
    </div>
  )
}

function Parent({src1})
{
  return(<div>
    <ResImage src1 = "https://images.unsplash.com/photo-1506744038136-46273834b3fb?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=1170&q=80" alt="RandomImage"/>
    <Link/>
    <ResCaption/>
    
  </div>)
}


createRoot(document.getElementById('root')).render(<Parent/>)
*/
function ResImage({src1,alt})
{
  return(
    <div>
      <img src={src1} alt={alt}/>
    </div>
  )
}

function ResCaption()
{
  return(
    <div>
      <p>This is a random image from Unsplash</p>
    </div>
  )
}

function Link()
{
  return(
    <div>
      <a href="https://unsplash.com/" target="_blank">Link to Unsplash</a>
    </div>
  )
}

function Parent(props)
{
  return(<div>
    <ResImage {...props}/>
    <Link/>
    <ResCaption/>
    
  </div>)
}

function Result()
{
  return(
  <div>
      <Parent src1="https://images.unsplash.com/photo-1506744038136-46273834b3fb?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=1170&q=80" alt="RandomImage"/>
    <div/>)
}
createRoot(document.getElementById('root')).render(<Result />)