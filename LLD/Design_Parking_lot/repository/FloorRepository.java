package LLD.Design_Parking_lot.repository;

import LLD.Design_Parking_lot.domain.Floor;

import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;
import java.util.UUID;
import java.util.Optional;
import java.util.List;


public class FloorRepository {
    private ConcurrentHashMap<UUID, Floor> floorsConcurrentHashMap = new ConcurrentHashMap<>();
    private ConcurrentHashMap<Integer, UUID> floorNumberToIdConcurrentHashMap = new ConcurrentHashMap<>();

    // save Floor by Id
    public void save(Floor floor) {
        floorsConcurrentHashMap.put(floor.getId(), floor);
        floorNumberToIdConcurrentHashMap.put(floor.getFloorNumber(), floor.getId());
    }

    // return floor by id
    public Optional<Floor> getFloorById(UUID floorId) {
        return Optional.ofNullable(floorsConcurrentHashMap.get(floorId));
    }

    // return all floors
    public List<Floor> getAllFloors() {
        return floorsConcurrentHashMap.values().stream().collect(Collectors.toList());
    }

    // check if the floor Number exists or Not
    public boolean isFloorNumberExists(Integer floorNumber) {
        return floorNumberToIdConcurrentHashMap.containsKey(floorNumber);
    }

    // delete a floor by id
    public void deleteFloorById(UUID floorId) {
        Floor floor = floorsConcurrentHashMap.remove(floorId);
        if (floor != null) {
            floorNumberToIdConcurrentHashMap.remove(floor.getFloorNumber());
        }
    }

    // clear all floors
    public void clearAllFloors() {
        floorsConcurrentHashMap.clear();
        floorNumberToIdConcurrentHashMap.clear();
    }
}
