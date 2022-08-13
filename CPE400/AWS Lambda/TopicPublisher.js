/*
  Copyright 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
  Permission is hereby granted, free of charge, to any person obtaining a copy of this
  software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify,
  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

//imports AWS SDK
var AWS = require('aws-sdk');
//creates a new AWS  IOT object
var iot = new AWS.Iot();
//sets name of the robot when publishing
var robotName = process.env.ROBOT_NAME;
//establishes the topic for the robot - KAR-pi/TOPIC
var publishTopic = `${robotName}/action`

//logs in lambda when an event happens
exports.handler = (event, context, callback) => {
  console.log("message received:", JSON.stringify(event.body, null, 2))
  //logs it into the robot's topic
  var params = {
       topic: publishTopic,
       payload: event.body,
       qos: 0
  }
  //publises received messages from website into the website's topic
  publishMessage(params, (err, res) => {
    callback(null, {
      //error handling
        statusCode: err ? '400' : '200',
        body: err ? err.message : JSON.stringify(res),
        headers: {
          // permissions access for aws iot
            'Content-Type': 'application/json',
            "Access-Control-Allow-Origin": "*"
        }
    })
  })
}
//creates publish message function
const publishMessage = (params, callback) => {
  //goes to endpoint of our AWS IOT function
  iot.describeEndpoint({}, (err, data) => {
    if(err){
      //handles error in the event it fails
      console.log(err)
      callback(err)
      //creates variable for where the IOT endpoint is
    }else{
      var iotdata = new AWS.IotData({endpoint: data.endpointAddress});
      iotdata.publish(params, (err, data) => {
        if(err){

          //handles error
          console.log(err)
          callback(err)
        }else{
          //throws success if there are no issues
          console.log("success?")
          callback(null, params)
        }
      })
    }
  })
}
