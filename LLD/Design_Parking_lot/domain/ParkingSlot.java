package LLD.Design_Parking_lot.domain;

import java.util.UUID;

public class ParkingSlot {
    private UUID id;
    private boolean isOccupied;
    private Integer floorNumber;
    private Vehicle.VehicleType slotType;
    // private enum SlotType {
    //     BIKE, CAR, TRUCK, EV
    // }

    public ParkingSlot(Vehicle.VehicleType vehicleType, Integer floorNumber) {
        this.id = UUID.randomUUID();
        this.isOccupied = false;
        this.floorNumber = floorNumber;
        this.slotType = vehicleType;
    }

    // Getters and Setters
    public UUID getId() {
        return id;
    }

    public boolean isOccupied() {
        return isOccupied;
    }

    public void setOccupied(boolean occupied) {
        isOccupied = occupied;
    }

    public Integer getFloorNumber() {
        return floorNumber;
    }

    public Vehicle.VehicleType getSlotType() {
        return slotType;
    }

    @Override
    public String toString() {
        return "ParkingSlot{" +
                "id=" + id +
                ", isOccupied=" + isOccupied +
                ", floorNumber=" + floorNumber +
                ", slotType=" + slotType +
                '}';
    }



}
