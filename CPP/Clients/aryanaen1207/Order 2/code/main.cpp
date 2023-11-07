Insert (Bid bid){
    extract the bid's key;
    key = generate the key usig hash function (hash(bid_key));
    node = get the node from the vector at given key position;

    check node is null
        add the newly creatd bid into that hashtble position;
    if not check node has unusable key
        change that old nodes's key to new key and bid to given bid;
    else
        add the node at the last of the linked list


}

printAll(){
    for every not null entry and has not UINT_MAX key, U in the hashtable
        print the key of U, bid's id,title,amount and fund
        update the current node is eqult to next node

        while current is not equal to null
            print the details of the nod's bid
            update the current ot its next address

}

remove(BidId){
    extract and get the hash table entry E using hash function

    get the vector entry N using E index

    if N is null return

    if N has the matching bidId
        temp = N;
        update N is to its next;
        free the temp address;

    else
        current node U is from E entry
        while next addrees of the u is not null
            check U' next has the key which is equal to BidId
                chacnge current address's next to next address of current's next
                free the node
                break
}

search(BidId){
        extract and get the hash table entry E using hash function

        get the current address by using E

        while current is not null
            check current key is equal to BidId
                return the bid
                break
        return emty bid
}