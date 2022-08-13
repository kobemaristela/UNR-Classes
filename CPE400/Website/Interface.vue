<template>
<!-- creates the new class with all the buttons used for controlling the robot -->
  <div class="hello">
    <button v-on:click="forward">
      <!-- when button is clicked, call the classes for handling the button presses -->
      <i class="arrow up" />
      <!-- up arrow -->
    </button>
    <div class="btn-group">
      <button v-on:click="left">
        <i class="arrow left" />
        <!-- left arrow -->
      </button>
      <button v-on:click="backwards">
        <i class="arrow down" />
        <!-- down arrow -->
      </button>
      <button v-on:click="right">
        <i class="arrow right" />
        <!-- right arrow -->
      </button>
    </div>
  </div>
</template>

<script>
// imports the authentication and API for handling robots
import { Auth, API } from 'aws-amplify'

//logs all authentication events
Auth.currentCredentials().then((info) => {
     console.log(info)
   });

//whenever a button is pressed, async function to post the data to the AWS Lambda poilcy
async function postData(dir) {
   let apiName = 'SendAction';
   //topic of where to post the data to
   let path = '/publish';
   let myInit = {
     body: {
       //action is the action taken - aka like forward, left, down, up, etc
       action: dir
     }
   }
   // returns what the api responds with
   return await API.post(apiName, path, myInit);
}


export default {
  name: 'Interface',
  methods: {
    // interface has 4 buttons, when forward is pressed, forward will be posted to AWS lambda
    forward: function () {
      postData('forward')
    },
    backwards: function () {
      // interface has 4 buttons, when backwards is pressed, backwards will be posted to AWS lambda
      postData('backwards')
    },
    left: function () {
      // interface has 4 buttons, when left is pressed, left will be posted to AWS lambda
      postData('left')
    },
    right: function () {
      // interface has 4 buttons, when right is pressed, right will be posted to AWS lambda
      postData('right')
    }
  }
}
</script>

<!-- sets basic style for the buttons -->
<style scoped>
i {

  /* sets the border and the how the buttons should display in the website */
  border: solid white;
  border-width: 0 3px 3px 0;
  display: inline-block;
  padding: 3px;
}
  /* all buttons on the website are the same image so we rotate them to save on storage and bandwidth
  for example, right button is rotated -90 degrees
  left button is rotated 270 degrees
  up button is rotated -270 degrees
  down button is rotated 90 degrees */
right {
  transform: rotate(-45deg);
  -webkit-transform: rotate(-45deg);
}

.left {
  transform: rotate(135deg);
  -webkit-transform: rotate(135deg);
}

.up {
  transform: rotate(-135deg);
  -webkit-transform: rotate(-135deg);
}

.down {
  transform: rotate(45deg);
  -webkit-transform: rotate(45deg);
}
button {
  /* sets the details about the buttons, oncluding the color margins, the pointer and the color  */
  min-width: 45px;
  display: inline-block;
  margin-bottom: 0;
  margin: 3px;
  vertical-align: middle;
  touch-action: manipulation;
  cursor: pointer;
  user-select: none;
  color: #fff;
  background-color: #f90;
  border-color: #ccc;
  padding: 14px 0;
  border: none;
  border-radius: 2px;
}
button:active {
  /* when buttons is pressed change the button to a new background color */
  opacity: 1;
  background-color: var(--button-click);
}
button:hover {
  opacity: 0.8;
}
</style>
