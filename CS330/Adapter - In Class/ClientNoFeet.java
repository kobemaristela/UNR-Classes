public class ClientNoFeet {
    GuitarController guitar;

    public ClientNoFeet(GuitarController controller){
        this.guitar = controller;
    }

    public void pressGreen(){
        guitar.pressFretButton(GuitarController.colors.GREEN);
    }

    public void pressRed(){
        guitar.pressFretButton(GuitarController.colors.RED);
    }

    public void pressYellow(){
        guitar.pressFretButton(GuitarController.colors.YELLOW);
    }

    public void pressBlue(){
        guitar.pressFretButton(GuitarController.colors.BLUE);
    }

    public void pressOrange(){
        guitar.pressFretButton(GuitarController.colors.ORANGE);
    }

    public void pickGuitar(){
        guitar.pressPick();
    }

    public void useTremelo(){
        guitar.pressTremelo();
    }
}
