package LLD.Design_Parking_lot.domain;

import LLD.Design_Parking_lot.domain.Vehicle;
import java.util.UUID;
import java.util.List;
import java.util.stream.Collectors;


public class Floor {

    private UUID id;
    private Integer floorNumber;
    private List<ParkingSlot> parkingSlots;

    public Floor(Integer floorNumber, List<ParkingSlot> parkingSlots) {
        this.id = UUID.randomUUID();
        this.floorNumber = floorNumber;
        this.parkingSlots = parkingSlots;
    }

    public UUID getId() {
        return id;
    }

    public Integer getFloorNumber() {
        return floorNumber;
    }

    // Get available parking slot
    public List<ParkingSlot> getAvailableParkingSlots(Vehicle.VehicleType vehicleType) {
        return parkingSlots.stream().filter(slot -> !slot.isOccupied() && slot.getSlotType() == vehicleType).collect(Collectors.toList());
    }

    // add new slot
    public void addParkingSlot(ParkingSlot parkingSlot) {
        this.parkingSlots.add(parkingSlot);
    }

}
