
public class WABigFactory extends BIGFactory{
	
	public SlotMachine createSlotMachine (String slot_type) {
		if (slot_type.equals("straight")) {
			return new WAStraightSlot();
		} else if (slot_type.equals("progressive")) {
			return new WAProgressiveSlot();
		} else if (slot_type.equals("bonus")) {
			return new WABonusGameSlot();
		} else return null;
	}
}
