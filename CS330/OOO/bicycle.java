public class bicycle extends Vehicle{
    // Attributes
    private wheel bikeWheel;

    
    // Constructor
    public bicycle() {
    	bikeWheel = new wheel();
    	bikeWheel.setSize(2);
    }
    
    public bicycle(Vehicle veh) {
    	bikeWheel = new wheel();
    	bikeWheel.setSize(2);
    	
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
    	return bikeWheel.getSize();
    }

    // Setters
    public void setColor(String color){
        setMyColor(color);
    }

    public void setName(String name){
        setMyName(name);
    }

    // Methods
    public void pedal(){
        System.out.println("Pedaling...");
    }
}