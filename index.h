const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<link rel="preconnect" href="https://fonts.gstatic.com">
<link href="https://fonts.googleapis.com/css2?family=Mountains+of+Christmas:wght@700&display=swap" rel="stylesheet">
<style>
.card{
    position: absolute;
    left: 50%;
    top: 50%;
    transform: translate(-50%, -50%);
    min-width: 40%;
    max-width: 90%;
    min-height: 250px;
    background: #02b875;
    padding: 30px;
    box-sizing: border-box;
    color: #FFF;
    margin:20px;
    box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
    vertical-align: middle;
    text-align: center;
}

.winter-is-coming, .snow {
  z-index: 100;
  pointer-events: none;
}

.winter-is-coming {
  overflow: hidden;
  position: absolute;
  top: 0;
  height: 100%;
  width: 90%;
  max-width: 100%;
}

.snow {
  position: absolute;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  -webkit-animation: falling linear infinite both;
          animation: falling linear infinite both;
  -webkit-transform: translate3D(0, -100%, 0);
          transform: translate3D(0, -100%, 0);
}
.snow--near {
  -webkit-animation-duration: 10s;
          animation-duration: 10s;
  background-image: url("https://dl6rt3mwcjzxg.cloudfront.net/assets/snow/snow-large-075d267ecbc42e3564c8ed43516dd557.png");
  background-size: contain;
}
.snow--near + .snow--alt {
  -webkit-animation-delay: 5s;
          animation-delay: 5s;
}
.snow--mid {
  -webkit-animation-duration: 20s;
          animation-duration: 20s;
  background-image: url("https://dl6rt3mwcjzxg.cloudfront.net/assets/snow/snow-medium-0b8a5e0732315b68e1f54185be7a1ad9.png");
  background-size: contain;
}
.snow--mid + .snow--alt {
  -webkit-animation-delay: 10s;
          animation-delay: 10s;
}
.snow--far {
  -webkit-animation-duration: 30s;
          animation-duration: 30s;
  background-image: url("https://dl6rt3mwcjzxg.cloudfront.net/assets/snow/snow-small-1ecd03b1fce08c24e064ff8c0a72c519.png");
  background-size: contain;
}
.snow--far + .snow--alt {
  -webkit-animation-delay: 15s;
          animation-delay: 15s;
}

@-webkit-keyframes falling {
  0% {
    -webkit-transform: translate3D(-7.5%, -100%, 0);
            transform: translate3D(-7.5%, -100%, 0);
  }
  100% {
    -webkit-transform: translate3D(7.5%, 100%, 0);
            transform: translate3D(7.5%, 100%, 0);
  }
}

@keyframes falling {
  0% {
    -webkit-transform: translate3D(-7.5%, -100%, 0);
            transform: translate3D(-7.5%, -100%, 0);
  }
  100% {
    -webkit-transform: translate3D(7.5%, 100%, 0);
            transform: translate3D(7.5%, 100%, 0);
  }
}
</style>
<body style="background-image: url('https://wallpapercave.com/wp/Tu9lcXU.jpg'); background-size: 100%;">

<div class="winter-is-coming">
  
  <div class="snow snow--near"></div>
  <div class="snow snow--near snow--alt"></div>
  
  <div class="snow snow--mid"></div>
  <div class="snow snow--mid snow--alt"></div>
  
  <div class="snow snow--far"></div>
  <div class="snow snow--far snow--alt"></div>
</div>

<p><span id="information" style="color: #848484;"></span></p>
<div class="card">
  <p style="font-size: 120px; font-family: 'Mountains of Christmas', cursive;"><span id="name">Santa Claus</span></p>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 1000);

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("name").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "nextName", true);
  xhttp.send();
  /*var infoXhttp = new XMLHttpRequest();
  infoXhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("information").innerHTML = this.responseText;
    }
  };
  infoXhttp.open("GET", "battery ", true);
  infoXhttp.send();*/
}
</script>
</body>
</html>
)=====";
