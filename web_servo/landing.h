static const char landing_html[] PROGMEM = R"====(
  <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
      <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    </head>
    <body>
      <div class="container">
        <div class="jumbotron text-center">
          <h1>LIGHTS</h1>
        </div>

        <div class="container text-center">
          <form class="row" action="on">
            <button class="btn btn-primary"> ON </button>
          </form>

          <form class="row" action="off">
            <button class="btn btn-danger"> OFF </button>
          </form>
        </div>
      </div>
    </body>
  </html>
)====";

// <div style="display: flex; flex-direction: column; justify-content: center; align-items: center; min-width: 100%; min-height: 100%">