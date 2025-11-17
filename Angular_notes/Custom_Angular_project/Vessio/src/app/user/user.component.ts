import { Component, signal, computed  } from '@angular/core';
import { DUMMY_USERS } from '../dummy-users';

@Component({
  selector: 'app-user',
  standalone: true,
  templateUrl: './user.component.html',
  styleUrls: ['./user.component.css']
})
export class UserComponent {
    randomIndex = Math.floor(Math.random()*DUMMY_USERS.length);

    selectedUser = signal(DUMMY_USERS[this.randomIndex]);

    UserIdandName = computed(()=>{return this.selectedUser().id + this.selectedUser().name});

    // getUserIdAndName(){
    //   return this.selectedUser.id + ' ' + this.selectedUser.name;
    // }

    onSelecteduser(){
      this.randomIndex = Math.floor(Math.random()*DUMMY_USERS.length);
      // this.selectedUser = DUMMY_USERS[this.randomIndex];
      this.selectedUser.set(DUMMY_USERS[this.randomIndex]);
    }

}
