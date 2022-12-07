
public class WAStore implements SlotMachineStore{
	
	public SlotMachine createStraight() {
		WASlotPieceFactory wa_factory = new WASlotPieceFactory();
		SlotMachine slot = wa_factory.createSlotMachine("straight");
		
		return slot;
	}
	
	public SlotMachine createBonus(){
		WASlotPieceFactory wa_factory = new WASlotPieceFactory();
		SlotMachine slot = wa_factory.createSlotMachine("bonus");
		
		return slot;
		
	}
	public SlotMachine createProgressive(){
		WASlotPieceFactory wa_factory = new WASlotPieceFactory();
		SlotMachine slot = wa_factory.createSlotMachine("progressive");
		
		return slot;
	}
}
