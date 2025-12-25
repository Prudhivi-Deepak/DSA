import { provideRouter, withComponentInputBinding, CanMatchFn, Router, RedirectCommand, mapToCanDeactivate, ResolveFn } from '@angular/router';
import { Component, inject } from '@angular/core';
import { NoTaskComponent } from './tasks/no-task/no-task.component';
import { resolverFunction, UserTasksComponent } from './users/user-tasks/user-tasks.component';
// import { resolveUserTasks, TasksComponent } from './tasks/tasks.component';
// import { canLeavePage, NewTaskComponent } from './tasks/new-task/new-task.component';
// import { Title } from '@angular/platform-browser';
import { NotFoundComponent } from './not-found/not-found.component';
// import { Task } from './tasks/task/task.model';
// import { TasksService } from './tasks/tasks.service';
// import { userRoutes } from './users/users.route';


const dummyCanMatchGuard: CanMatchFn = (route, segments) => {
    const router = inject(Router);
    const canGiveAccess = Math.random();
    if (canGiveAccess < 1) {
        return true;
    }

    // return router.parseUrl('/');
    return new RedirectCommand(router.parseUrl('/unauthorized'));
}

export const routes = [
    {
        path: '', component: NoTaskComponent,
        // title: resolverFunctionForTitle
        // title: 'No Tasks Available'
    },
    // {
    //     path: 'tasks', component: TaskComponent
    // }
    {
        path: 'users/:userId', component: UserTasksComponent,
        // children: userRoutes,
        loadChildren: () => import('./users/users.route').then(m => m.userRoutes),
        data: {
            message: 'User Tasks Page'
        },
        resolve: {
            userName: resolverFunction
        },
        canMatch: [dummyCanMatchGuard],
    },
    {
        path: '**', component: NotFoundComponent,
    }
];