import { InjectionToken, NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { TasksComponent } from './tasks/tasks.component';
import { TasksListComponent } from './tasks/tasks-list/tasks-list.component';
import { NewTaskComponent } from './tasks/new-task/new-task.component';
import { TaskItemComponent } from './tasks/tasks-list/task-item/task-item.component';
import { TasksService } from './tasks/tasks.service';
import { FormsModule } from '@angular/forms';

export const TokenServiceToken = new InjectionToken<TasksService>('Token-task-service');

@NgModule({
    declarations: [
        AppComponent,
        TasksComponent,
        NewTaskComponent, TasksListComponent,
        TaskItemComponent
    ],
    imports: [
        BrowserModule, FormsModule
    ],
    //   providers: [{provide: TasksService, useClass: TasksService}],
    providers: [{ provide: TokenServiceToken, useClass: TasksService }],
    bootstrap: [AppComponent]
})
export class AppModule { }
