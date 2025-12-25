import { Component, signal, computed, Input, input, output, EventEmitter, Output  } from '@angular/core';
import { DUMMY_USERS } from '../dummy-users';
import { type User } from './user.model';
// type User = {
//   id: string;
//   name:  string;
//   avatar: string;
// };

// interface User {
//   id: string;
//   name:  string;
//   avatar: string;
// }

@Component({
  selector: 'app-user',
  // standalone: true,
  standalone: false,
  templateUrl: './user.component.html',
  styleUrls: ['./user.component.css']
})

export class UserComponent {
    // randomIndex = Math.floor(Math.random()*DUMMY_USERS.length);
    // selectedUser = signal(DUMMY_USERS[this.randomIndex]);
    // UserIdandName = computed(()=>{return this.selectedUser().id + this.selectedUser().name});
    // getUserIdAndName(){
    //   return this.selectedUser.id + ' ' + this.selectedUser.name;
    // }

    // @Input({required: true}) id!: string;
    // @Input() avatar!: string;
    // @Input({required: true}) name!: string;

    @Input({required: true}) user!: User;
    @Input() isUserSelected: boolean = false;

    @Output() userSelected = new EventEmitter<string>();

    get UserIdAndName(){
      // return this.id + ' ' + this.name;
      return this.user?.id + ' ' + this.user?.name;
    }
    
    // id = input.required<string>();
    // avatar = input<string>();
    // name = input.required<string>();
    // UserIdAndName = computed(()=>{return this.id() + ' ' + this.name()});

    onSelecteduser(){
      // this.randomIndex = Math.floor(Math.random()*DUMMY_USERS.length);
      // this.selectedUser = DUMMY_USERS[this.randomIndex];
      // this.selectedUser.set(DUMMY_USERS[this.randomIndex]);
      this.userSelected.emit(this.user.id);
    }

}
