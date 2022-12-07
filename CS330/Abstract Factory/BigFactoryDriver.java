
public class BigFactoryDriver {

	public static void main(String[] args) {
		
		// Creating stores
		NVStore nv_machine = new NVStore();
		NJStore nj_machine = new NJStore();
		WAStore wa_machine = new WAStore();
		
		
		System.out.println("The Taj Mahal orders a:");
		SlotMachine nv_slot = nv_machine.createStraight();
		nv_slot.play();
		
		// Peppermill /w NJ Progressive Game Slot machine
		System.out.println("\nThe Peppermill orders a:");
		SlotMachine nj_slot = nj_machine.createProgressive();
		nj_slot.play();
		
		// Circus Circus /w WA Bonus Slot machine
		System.out.println("\nThe Circus Circus orders a:");
		SlotMachine wa_slot = wa_machine.createBonus();
		wa_slot.play();
	}

}
