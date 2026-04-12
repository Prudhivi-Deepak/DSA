import { Component } from '@angular/core';
import { HeaderComponent } from './header/header.component';
import { UserComponent } from './user/user.component';
import { DUMMY_USERS } from './dummy-users';
import { TasksComponent } from './tasks/tasks.component';
// import {NgFor, NgIf} from '@angular/common';


@Component({
  selector: 'app-root',
  // standalone: true,
  standalone: false,
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  // imports: [HeaderComponent, UserComponent, TasksComponent, NgFor, NgIf],
})
export class AppComponent {
  title = 'Vessio';
  users = DUMMY_USERS
  // selectedUserId: string | null = null;
  selectedUserId?: string;

  OnUserSelected(userId: string){
    this.selectedUserId = userId;
  }
}
