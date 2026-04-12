package LLD.Design_Parking_lot.repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.UUID;
import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;
import LLD.Design_Parking_lot.domain.Payment;


public class PaymentRepository {
    // there will be many payments either success or failures
    // for each ticket ther emight be 3 Failure and 1 success payments
    // So we use a map tos tore payments with payments ids as key and payment object as value
    // and another map to store ticketId and list of paymentIds for that ticket
     private ConcurrentHashMap<UUID, Payment> paymentsConcurrentHashMap = new ConcurrentHashMap<>();
     private ConcurrentHashMap<UUID, List<UUID>> ticketPaymentsConcurrentHashMap = new ConcurrentHashMap<>();

    //  save payment
    public Payment savePayment(Payment payment){
        paymentsConcurrentHashMap.put(payment.getId(), payment);
        ticketPaymentsConcurrentHashMap.computeIfAbsent(payment.getTicketId(), k -> new ArrayList<>()).add(payment.getId());
        return payment;
    }

    // get payment by id
    public Optional<Payment> getPaymentById(UUID paymentId){
        return Optional.ofNullable(paymentsConcurrentHashMap.get(paymentId));
    }

    public List<Payment> getPaymentsByTicketId(UUID ticketId){
        List<UUID> paymentIds = ticketPaymentsConcurrentHashMap.get(ticketId);
        if(paymentIds == null){
            return new ArrayList<>();
        }
        return paymentIds.stream()
                .map(paymentId -> paymentsConcurrentHashMap.get(paymentId))
                .filter(payment -> payment != null)
                .collect(Collectors.toList());
    }

    // return all payments regardless of ticketId
    public List<Payment> getAllPayments(){
        return new ArrayList<>(paymentsConcurrentHashMap.values());
    }

    // delete a payment by id
    public void deletePaymentById(UUID paymentId){
        Payment payment = paymentsConcurrentHashMap.remove(paymentId);
        if(payment != null){
            List<UUID> paymentIdsbyTicketId = ticketPaymentsConcurrentHashMap.get(payment.getTicketId());
            if(paymentIdsbyTicketId != null){
                paymentIdsbyTicketId.remove(paymentId);
            }       
        }
    }

    // clear all payments
    public void clearAllPayments(){
        paymentsConcurrentHashMap.clear();
        ticketPaymentsConcurrentHashMap.clear();
    }

}
