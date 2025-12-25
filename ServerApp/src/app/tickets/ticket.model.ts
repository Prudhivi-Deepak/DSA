export interface Ticket {
    id: string;
    title: string;
    request: string;
    status: 'open' | 'in-progress' | 'closed';
    // createdAt: string;
}