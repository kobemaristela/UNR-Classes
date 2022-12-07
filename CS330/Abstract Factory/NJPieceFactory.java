
public class NJPieceFactory implements SlotMachinePieceFactory{
	

	public SlotMachine createSlotMachine (String slot_type) {
		
		SlotMachine slot = null;
		
		if (slot_type.equals("straight")) {
			slot = new StraightSlot();
			
			slot.cabinet = new SmallCabinet();
			slot.display = new LCDDisplay();
			slot.payment = new CoinsPayment();
			slot.cpu = new ArmCPU();
			slot.os = new WinMEOS();
		} else if (slot_type.equals("progressive")) {
			slot = new ProgressiveSlot();
			
			slot.cabinet = new SmallCabinet();
			slot.display = new CRTDisplay();
			slot.payment = new BillsPayment();
			slot.cpu = new X86CPU();
			slot.os = new WinXPOS();
		} else if (slot_type.equals("bonus")) {
			slot = new BonusSlot();
			
			slot.cabinet = new LargeCabinet();
			slot.display = new ReelsDisplay();
			slot.payment = new CoinsPayment();
			slot.cpu = new ArmCPU();
			slot.os = new WinMEOS();		}
		
		return slot;
	}
}
