import { Component, computed, inject, Input, input } from '@angular/core';
import { UsersService } from '../users.service';
import { RouterLinkActive, RouterOutlet, RouterLink, ResolveFn, ActivatedRoute, ActivatedRouteSnapshot, RouterStateSnapshot } from '@angular/router';

@Component({
  selector: 'app-user-tasks',
  imports: [RouterOutlet, RouterLink],
  standalone: true,
  templateUrl: './user-tasks.component.html',
  styleUrl: './user-tasks.component.css',
})
export class UserTasksComponent {
  // userId1 = input.required<string>();
  @Input({required: true}) userId!: string;
  message = input.required<string>();
  userName = input.required<string>();

  userService = inject(UsersService);
  users = this.userService.users;

  ngOnInit(){
    console.log('this.message : ', this.message());
  }

  // userName = computed(()=> this.userService.users.filter(user=> user.id === this.userId1())[0].name);
  // get userName(){
  //   // return this.userService.users.filter(user=> user.id === this.userId1)[0]?.name || '';
  //   return this.users.find(user=> user.id === this.userId)?.name || '';
  // }

}


export const resolverFunction : ResolveFn<string> = (activatedRoute: ActivatedRouteSnapshot, routeStateSnapShot: RouterStateSnapshot)=>{
  const userService = inject(UsersService);
  const userName = userService.users.find(user=> user.id === activatedRoute.params['userId'])?.name || '';
  return userName;
}

export const resolverFunctionForTitle : ResolveFn<string> = (activatedRoute: ActivatedRouteSnapshot, routeStateSnapShot: RouterStateSnapshot)=>{
  return resolverFunction(activatedRoute, routeStateSnapShot)+' Tasks';
}