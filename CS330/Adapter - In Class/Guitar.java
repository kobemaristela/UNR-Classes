public class Guitar implements GuitarController{
    public void pressFretButton(colors button){
      System.out.println("Fret color: " + button);
    }

    public void pressPick(){
      System.out.println("Picking the guitar...");
    }

    public void pressTremelo(){
      System.out.println("Moving the tremelo...");
    }
  }