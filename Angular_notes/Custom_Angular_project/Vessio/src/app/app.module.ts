import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { UserComponent } from './user/user.component';
import { HeaderComponent } from './header/header.component';
// import { TasksComponent } from './tasks/tasks.component';
// import { NewTaskComponent } from './tasks/new-task/new-task.component';
// import { TaskComponent } from './tasks/task/task.component';
import { FormsModule } from '@angular/forms';
import { TaskModule } from './tasks/task.module';

@NgModule({
  declarations: [
    AppComponent, HeaderComponent, UserComponent, 
    // TasksComponent, TaskComponent, NewTaskComponent
  ],
  imports: [ 
    BrowserModule,
    AppRoutingModule,
    TaskModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
