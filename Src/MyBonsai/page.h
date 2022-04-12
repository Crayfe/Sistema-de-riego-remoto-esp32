/*PAGINA HTML CON UN BOTÓN INTERACTIVO PARA REGAR UN BONSAI
* POR: @Crayfe
*/
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html"; charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="icon" href="data:,">
        <link href="https://fonts.googleapis.com/css?family=Cabin+Sketch&display=swap" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=VT323&display=swap" rel="stylesheet">
        <style>
            body {background-image: url(https://i.ibb.co/h74tZ22/wallpaper.jpg);background-attachment: fixed; text-align: center;font-family: 'Cabin Sketch', cursive;}
            .header{padding: 0px; width:400px; height:150px;}
            .testInput{padding: 15px; width:400px;}
            .logo{float:left; padding: 30px 10px 20px 20px;}
            .title-header{font-family: 'Cabin Sketch', cursive; font-size: 45px; color: black; float:right; margin-top:60px; margin-bottom:0px;margin-right: 40px;}
            .wrap{padding:20px;width: 470px;margin-right: auto; margin-left: auto;display: inline-block;}
            .content{background-image: url(https://i.ibb.co/H2k5kdP/papel.jpg); padding: 5px 20px 20px 20px; margin-top: 20px;}
            .button{background-color: #195B6A; border: none; color: white; padding: 16px 20px; font-family: 'VT323', monospace;text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}
            .button2{background-color: #9AFF40; border: none; color: white; padding: 16px 20px; font-family: 'VT323', monospace;text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}
            .input_text{color: black; padding: 16px;text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}
            .separator{border-color: #000;}
        </style>
    </head>

<body> 
    <div class="wrap">
    <div class="content">
        <div class="header">
            <img class="logo" src="https://i.ibb.co/NYhkGSR/bonsai.png" height="90" width="80">
            <h1 class="title-header">My bonsai</h1></p>
        </div>
        <hr class="separator"/>
        <div class="testInput">
            <p><h2 style="font-family: 'Cabin Sketch';">Test de riego</h2></p>
            <p><input type="text" id="delayRiego" class="input_text" size="5"name="delayR">&nbsp;ms&nbsp;&nbsp;&nbsp<button class="button" id="bt" onclick="sendData()">Regar bonsái</button></p>
        </div>
        <hr class="separator"/> 
    </div>
    </div>
    <script>
      var button = document.getElementById("bt");
      function sendData() {
        var rl = document.getElementById("delayRiego").value;
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("bt").innerHTML =
            this.responseText;
            button.className = "button2";
          }
        };
        xhttp.open("GET", "setRelay?Relay="+rl, true);
        xhttp.send();
      }
      function getData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("bt").innerHTML =
            this.responseText;
            button.className = "button";
          }
        };
        xhttp.open("GET", "readState", true);
        xhttp.send();
      }
      setInterval(function() {getData();}, 500);
    </script>
</body>
</html>
)=====";
