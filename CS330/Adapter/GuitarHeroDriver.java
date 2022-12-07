public class GuitarHeroDriver {
    public static void main(String[] args) {
        // Initialize variables - Instruments & Adapters
        Guitar guitar = new Guitar();
        Dance dance = new Dance();

        DanceController guitarAdapter = new GuitarAdapter(guitar);
        GuitarController danceAdapter = new DanceAdapter(dance);

        // Assignment - PART 2
        System.out.println("-----GUITAR ADAPTER TEST /w CientNoHands-----");
        ClientNoHands noHands = new ClientNoHands(guitarAdapter);
        noHands.moveForward();
        noHands.moveBack();
        noHands.moveLeft();
        noHands.moveRight();
        noHands.moveMiddle();

        noHands.moveForwardAndBack();
        noHands.moveRightAndLeft();


        // Assignment - PART 3
        System.out.println("\n-----DANCE ADAPTER TEST /w ClientNoFeet-----");
        ClientNoFeet noFeet = new ClientNoFeet(danceAdapter);
        noFeet.pressGreen();
        noFeet.pressRed();
        noFeet.pressYellow();
        noFeet.pressOrange();
        noFeet.pressBlue();

        noFeet.pickGuitar();
        noFeet.useTremelo();
    }
}
