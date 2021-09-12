//
//  simdef.h
//  5_05
//
//  Created by Wonkeun No on 2020-04-12.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef simdef_h
#define simdef_h

typedef enum SimStatusType {
    arrival, start, end
}SimStatus;

typedef struct SimCustomerType {
    SimStatus status;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
}SimCustomer;

#endif /* simdef_h */

