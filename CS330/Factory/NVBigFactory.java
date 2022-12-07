
public class NVBigFactory extends BIGFactory{

	public SlotMachine createSlotMachine (String slot_type) {
		if (slot_type.equals("straight")) {
			return new NVStraightSlot();
		} else if (slot_type.equals("progressive")) {
			return new NVProgressiveSlot();
		} else if (slot_type.equals("bonus")) {
			return new NVBonusGameSlot();
		} else return null;
	}

}
