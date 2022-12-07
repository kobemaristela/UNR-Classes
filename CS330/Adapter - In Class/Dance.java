public class Dance implements DanceController{
    public void step(direction dir1, direction dir2){
        if(dir2 == null){
            System.out.println("Step direction: " + dir1);
            return;
        }

        System.out.println("Step directions: " + dir1 + "&" + dir2);
    }
  }