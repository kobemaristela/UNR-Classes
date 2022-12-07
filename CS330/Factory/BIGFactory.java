
public abstract class BIGFactory {

	public SlotMachine orderSlotGame(String type) {
		SlotMachine slot;
		
		slot = createSlotMachine(type);
		
		slot.getOrder();
		slot.fetchComponents();
		slot.assembleComponents();
		slot.testHardware();
		slot.uploadSoftware();
		slot.testSoftware();
		
		return slot;
	}

	abstract SlotMachine createSlotMachine(String slot_type);
}
