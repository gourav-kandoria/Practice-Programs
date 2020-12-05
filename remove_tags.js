//var x = document.getElementsByClassName("tag-box");
//x[0].parentNode.parentNode.remove();

var panels = document.getElementsByClassName("panel problem-block");

for(var i=0; i<panels.length; i++) {
  var child = panels[i].querySelectorAll('.text-muted');
  if(child) {
    for(var j=0; j<child.length; j++) {
      child[j].remove();
    }
  }
}

