/*
============================================
JavaScript for AJAX request.
Gets and handles JSON data from the server.
Virtuaaliluonto 1.4.2018
============================================
*/


// Points to a table class in HTML

function getData () {


	// Request & receive JSON Data
	var pageRequest = new XMLHttpRequest();
	pageRequest.open('GET', '/data');
	pageRequest.onload = function() {

		// Save JSON data to a variable
		var mySensorData = JSON.parse(pageRequest.responseText);
		// Call the renderTest function and pass it to mySensorData variable
		renderData(mySensorData);
	};


// Send the request
pageRequest.send();

} // Function ends here

	// Call function before setting an interval
	getData();
	// Set Interval. Last argument is in milliseconds NOTE: setInterval() keeps triggering expression again and again unless you tell it to stop
	setInterval( getData, 5000 );
	
// Add HTML to the page. Array of objects is accessed with "data".
function renderData(data) {
	var htmlString = "";
	

      
// variables and their funtions	  
	var currentTime = new Date(),
      hours = currentTime.getHours(),
      minutes = currentTime.getMinutes();

	if (minutes < 10) {
	 minutes = "0" + minutes;
  }
   document.write(hours + ":" + minutes)
   
	var depthhtml=  "<td class='snow depth'>";
	
	if (data.depth > 0) {
    depthhtml = "<td class='Snow depth'>";}

	var temphtml = "<td class='temperature'>";
    if (data.temp > -50) {
    temphtml = "<td class='temperature'>";}
	
	// Add elements to htmlString

	htmlString += "<tr><td>" + "CurrentTime" + "</td>"+ depthhtml + data.depht+ "</td>" + temphtml + data.temp + "</td></tr>";
}
