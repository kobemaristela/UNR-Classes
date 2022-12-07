
public abstract class SlotMachine {
	String name;
	String cabinet;
	String payment;
	String display;
	String cpu;
	String os;
	
	public void fetchComponents()
	{
		System.out.println(String.format("fetching components: %s Cabinet, %s validator, %s display, %s", this.cabinet, this.payment, this.display, this.cpu));
	}
	
	public void assembleComponents() {
		System.out.println("Assembling components...");
	}
	
	public void testHardware() {
		System.out.println("Testing hardware...");
	}
	
	public void uploadSoftware() {
		System.out.println("Uploading software... " + this.os);
	}
	
	public void testSoftware() {
		System.out.println("Testing software...");
	}
	
	public void getOrder() {
		System.out.println(String.format("---  %s ---", this.name));
	}
}
