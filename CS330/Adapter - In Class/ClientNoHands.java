public class ClientNoHands {
    DanceController dance;

    public ClientNoHands(DanceController controller){
        this.dance = controller;
    }

    public void moveForward(){
        dance.step(DanceController.direction.FORWARD,null);
    }

    public void moveBack(){
        dance.step(DanceController.direction.BACK,null);
    }

    public void moveLeft(){
        dance.step(DanceController.direction.LEFT,null);
    }

    public void moveRight(){
        dance.step(DanceController.direction.RIGHT,null);
    }

    public void moveMiddle(){
        dance.step(DanceController.direction.MIDDLE,null);
    }

    public void moveForwardAndBack(){
        dance.step(DanceController.direction.FORWARD,DanceController.direction.BACK);  // Pick guitar
    }

    public void moveRightAndLeft(){
        dance.step(DanceController.direction.RIGHT,DanceController.direction.LEFT);  // Move tremelo
    }
}
