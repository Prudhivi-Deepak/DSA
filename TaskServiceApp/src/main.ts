import { bootstrapApplication, platformBrowser } from '@angular/platform-browser';
import { InjectionToken } from '@angular/core';
import { AppComponent } from './app/app.component';
import { TasksService } from './app/tasks/tasks.service';
import { AppModule } from './app/app.module';

// import { AppComponent } from './app/app.component';
// export const TokenServiceToken = new InjectionToken<TasksService>('Token-task-service');

// bootstrapApplication(AppComponent,
//     {
//         providers: [{ provide: TokenServiceToken, useClass: TasksService }]
//     }
//     // {
//     //     providers: [TasksService]
//     // }
// ).catch((err) => console.error(err));
platformBrowser().bootstrapModule(AppModule)
  .catch(err => console.error(err));
