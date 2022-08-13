<!-- main website's javascript -->

<template>
    <div id="app">
      <div v-if="!signedIn">
        <!-- establishes authentitcation with AWS amplify and cognito -->
         <amplify-authenticator></amplify-authenticator>
      </div>
      <div v-if="signedIn">
        <amplify-sign-out class="signout" v-bind:signOutOptions="signOutOptions"></amplify-sign-out>
        <!-- creates the header for our robot's website as well as inserts a picture of the robot -->
        <h1>CPE 400 Project</h1>
        <img src="./assets/robot.jpeg" alt="Web Rover" height="500" width="400">
        <Interface />
      </div>
    </div>
</template>

<script>
// imports our interface for controlling the robot - the 4 arrow keys
import Interface from './components/Interface.vue'
//import aws amplify event - for sending messages when the buttons are pressed
import { AmplifyEventBus, components } from 'aws-amplify-vue'
// imports authentication library for authorizing the users
import { Auth } from 'aws-amplify'

import * as AmplifyVue from 'aws-amplify-vue'

const signOutOptions = {
  // if user signs out of the website this will be displayed
  msg: 'You are currently signed in.',
  signOutButton: 'Sign Out'
}


//default names of the app, and tghe parts of the app that we need
export default {
  name: 'app',
  components: {
    //default components
    components,
    Interface
  },
  //asynchronous javasciript function to check to see if the user is signed in or not
  async beforeCreate() {
    try {
      //if user is signed in, set variable to signed in
      const user = await Auth.currentAuthenticatedUser()\
      //if not , reject the user
      this.signedIn = true
    } catch (err) {
      this.signedIn = false
    }
    //this logs whether a user is signed in or not into the console
    AmplifyEventBus.$on('authState', info => {
      console.log(info)
      if (info === 'signedIn') {
        this.signedIn = true
      } else {
        this.signedIn = false
      }
    });
  },
  data () {
    return {
      //returns the possible sign options
      signOutOptions,
      signedIn: false
    }
  }
}
</script>

<style>
/* establishes basic style of the website */
body {
  /* sets margin of the page to 0 */
  margin: 0
}
#app {
  /* sets the font of the website, along with the basic font settings */
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
.signout {
  /* sets the look of the sign in screen, including padding */
  background-color: #ededed;
  margin: 0;
  padding: 11px 0px 1px;
}
</style>
