
public abstract class SlotMachine {
	String name;
	Cabinet cabinet;
	Payment payment;
	Display display;
	CPU cpu;
	OS os;
	
	public abstract void play();
}
