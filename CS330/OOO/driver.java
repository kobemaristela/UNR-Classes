
public class driver {

	public static void main(String[] args) {
		// Test 1
        bicycle b1 = new bicycle();
        car c1 = new car();
        b1.pedal();
        c1.start();
        
        
       // Polymorphism - Test 2
        Vehicle c2 = new car();
        
        // Test Abstract - Car
        c2.setMyName("Kobe");
        System.out.println(c2.getMyName());
        
        c2.setMyColor("Red");
        System.out.println(c2.getMyColor());
        
        bicycle b2 = new bicycle(c2);
        b2.pedal();
        
        // Logic Check
        System.out.println("Car Name: " + b2.getMyName() + " | Car Color: " + b2.getMyColor() + " | Car Wheel Size: " + b2.getWheelSize());
        
        
        // Polymorphism - Test 3
        Vehicle b3 = new bicycle();
        
        // Test Abstract - Bicycle
        b3.setMyName("Amber");
        System.out.println(b3.getMyName());
        
        b3.setMyColor("Yellow");
        System.out.println(b3.getMyColor());
        
        car c3 = new car(b3);
        c3.start();
        
        // Logic Check
        System.out.println("Car Name: " + c3.getMyName() + " | Car Color: " + c3.getMyColor() + " | Car Wheel Size: " + c3.getWheelSize());
        
        
        

	}

}
