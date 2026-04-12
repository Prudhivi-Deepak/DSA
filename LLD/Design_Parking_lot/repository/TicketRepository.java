package LLD.Design_Parking_lot.repository;

import java.util.concurrent.ConcurrentHashMap;

import LLD.Design_Parking_lot.domain.Ticket;
import java.util.UUID;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class TicketRepository {
    // generate ticket & save ticket
    // find ticket by id
    // make ticket deactive

    // save all tickets in HashMap (UUID -> Ticket)

    private ConcurrentHashMap<UUID, Ticket> ticketsConcurrentHashMap = new ConcurrentHashMap<>();

    public Ticket saveTicket(Ticket ticket){
        ticketsConcurrentHashMap.put(ticket.getUUID(), ticket);
        return ticket;
    }

    public Optional<Ticket> getTicketById(UUID ticketId){
        return Optional.ofNullable(ticketsConcurrentHashMap.get(ticketId));
    }

    public List<Ticket> getAllActiveTickets(){
        return this.ticketsConcurrentHashMap.values().stream()
                // .filter(Ticket::isActiveTicket)
                .filter(ticket -> ticket.isActiveTicket())
                .collect(Collectors.toList());
    }

    public void deactivateTicket(UUID ticketId){
        // Ticket ticket = ticketsConcurrentHashMap.get(ticketId);
        // if(ticket != null){
        //     ticket.deactivate();
        //     ticketsConcurrentHashMap.put(ticketId, ticket);
        // }

        ticketsConcurrentHashMap.computeIfPresent(ticketId, (id, ticket) -> {
            ticket.deactivate();
            return ticket;
        });
    }

    public void clearAllTickets(){
        ticketsConcurrentHashMap.clear();
    }




}
