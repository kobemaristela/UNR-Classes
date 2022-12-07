
public class BigFactoryDriver {

	public static void main(String[] args) {
		// Taj Mahal /w NV Straight Slot Machine
		BIGFactory nv_machine = new NVBigFactory();
		
		System.out.println("The Taj Mahal orders a:");
		SlotMachine nv_slot = nv_machine.orderSlotGame("straight");
		
		// Peppermill /w NJ Bonus Game Slot machine
		BIGFactory nj_machine = new NJBigFactory();
		
		System.out.println("\nThe Peppermill orders a:");
		SlotMachine nj_slot = nj_machine.orderSlotGame("bonus");
		
		// Circus Circus /w WA Progressive Slot machine
		BIGFactory wa_machine = new WABigFactory();
		
		System.out.println("\nThe Circus Circus orders a:");
		SlotMachine wa_slot = wa_machine.orderSlotGame("progressive");

	}

}
