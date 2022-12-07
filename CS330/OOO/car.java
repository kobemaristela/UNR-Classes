public class car extends Vehicle{
	// Attributes
	private wheel carWheel;

   public car() {
	   carWheel = new wheel();
	   carWheel.setSize(4);
   }
   
   public car(Vehicle veh) {
	   carWheel = new wheel();
	   carWheel.setSize(4);
   
		setColor(veh.getMyColor());
		setName(veh.getMyName());
   }

   // Getters
   public String getColor(){
      return getMyColor();
   }

   public String getName(){
      return getMyName();
   }
   
   public int getWheelSize() {
   	return carWheel.getSize();
   }

   // Setters
   public void setColor(String color){
      this.setMyColor(color);
   }

   public void setName(String name){
      this.setMyName(name);
   }

   // Methods
   public void start(){
    System.out.println("Starting...");
    }
}
