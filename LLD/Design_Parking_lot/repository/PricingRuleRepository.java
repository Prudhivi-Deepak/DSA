package LLD.Design_Parking_lot.repository;

import java.util.concurrent.ConcurrentHashMap;
import java.util.UUID;
import LLD.Design_Parking_lot.domain.PricingRule;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class PricingRuleRepository {
    private ConcurrentHashMap<UUID, PricingRule> pricingRulesConcurrentHashMap = new ConcurrentHashMap<>();

    // save pricingRule for each vechcielType
    public PricingRule savePricingRule(PricingRule pricingRule) {
        pricingRulesConcurrentHashMap.put(pricingRule.getId(), pricingRule);
        return pricingRule;
    }

    // get pricingRule by vehicleType
    public Optional<PricingRule> getPricingRuleByVehicleType(PricingRule.VehicleType vehicleType) {
        return pricingRulesConcurrentHashMap.values().stream()
                .filter(pricingRule -> pricingRule.getVehicleType() == vehicleType)
                .findFirst();
                // .map(pricingslot->{
                //     return pricingslot;
                // });
    }

    // get pricingRule by id
    public Optional<PricingRule> getPricingRuleById(UUID pricingRuleId) {
        return Optional.ofNullable(pricingRulesConcurrentHashMap.get(pricingRuleId));
    }

    // set new pricing rule by vehicle type
    public void updatePricingRuleByVehicleType(PricingRule.VehicleType vehicleType, PricingRule newPricingRule) {
        pricingRulesConcurrentHashMap.values().stream()
                .filter(pricingRule -> pricingRule.getVehicleType() == vehicleType)
                .findFirst()
                .ifPresent(pricingRule -> {
                    pricingRule.setFlatRateAndRatePerHour(newPricingRule.getFlatRate(), newPricingRule.getRatePerHour());
                    pricingRulesConcurrentHashMap.put(pricingRule.getId(), pricingRule);
                });
    }

    // return all pricing rules
    public List<PricingRule> getAllPricingRules() {
        return new ArrayList<>(pricingRulesConcurrentHashMap.values());
    }

    // delete a rule
    public void deletePricingRuleById(UUID pricingRuleId) {
        pricingRulesConcurrentHashMap.remove(pricingRuleId);
    }

    // clear all rules
    public void clearAllPricingRules() {
        pricingRulesConcurrentHashMap.clear();
    }

}
