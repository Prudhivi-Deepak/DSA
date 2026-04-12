package LLD.Design_Parking_lot.repository;

import LLD.Design_Parking_lot.domain.ParkingSlot;
import LLD.Design_Parking_lot.domain.Vehicle;
import java.util.concurrent.ConcurrentHashMap;
import java.util.UUID;
import java.util.Optional;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Map;

public class SlotRepository {
    private ConcurrentHashMap<UUID, ParkingSlot> slotsConcurrentHashMap = new ConcurrentHashMap<>();

    // save Slotby Id
    public void save(ParkingSlot parkingSlot) {
        slotsConcurrentHashMap.put(parkingSlot.getId(), parkingSlot);
    }

    // return slot by id
    public Optional<ParkingSlot> getSlotById(UUID slotId) {
        return Optional.ofNullable(slotsConcurrentHashMap.get(slotId));
    }

    // return all available slots by type
    public List<ParkingSlot> getAvailableSlotByType(Vehicle.VehicleType vehicleType) {
        return slotsConcurrentHashMap.values().stream()
                .filter(slot -> !slot.isOccupied() && slot.getSlotType() == vehicleType)
                .collect(Collectors.toList());
    }

    // allocate Slot by using slotId
    public Optional<ParkingSlot> AllocateSlotByIdAndVehicleType(UUID slotId, Vehicle.VehicleType vehicleType){
        return slotsConcurrentHashMap.values().stream()
        .filter(slot-> (slot.getSlotType() == vehicleType && slot.getId() == slotId))
        .findFirst()
        .map(slot -> {
            slot.setOccupied(true);
            return slot;
        });
    }

    // release slot
    public void releaseSlot(UUID slotId){
        slotsConcurrentHashMap.values().stream()
        .filter(slot-> slot.getId() == slotId)
        .findFirst()
        .ifPresent(slot -> slot.setOccupied(false));
    }

    // return all slots vehicleType vise
    public Map<Vehicle.VehicleType, Long> getAllSlotsStatisticsByAllVehicleType(){
        return slotsConcurrentHashMap.values().stream()
        .collect(Collectors.groupingBy(slot-> slot.getSlotType(), Collectors.counting()));
    }

    // clear all slots
    public void clearAllSlots() {
        slotsConcurrentHashMap.clear();
    }

}
