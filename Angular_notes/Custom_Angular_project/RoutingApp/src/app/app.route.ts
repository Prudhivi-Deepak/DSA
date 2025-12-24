import { provideRouter, withComponentInputBinding, CanMatchFn, Router, RedirectCommand, mapToCanDeactivate } from '@angular/router';
import { Component, inject } from '@angular/core';
import { NoTaskComponent } from './tasks/no-task/no-task.component';
import { resolverFunction, resolverFunctionForTitle, UserTasksComponent } from './users/user-tasks/user-tasks.component';
import { resolveUserTasks, TasksComponent } from './tasks/tasks.component';
import { canLeavePage, NewTaskComponent } from './tasks/new-task/new-task.component';
import { Title } from '@angular/platform-browser';
import { NotFoundComponent } from './not-found/not-found.component';

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
        children: [
            {
                path: 'tasks', component: TasksComponent,
                // runGuardsAndResolvers: 'paramsOrQueryParamsChange',
                runGuardsAndResolvers: 'always' as const,
                resolve: {
                    userTasks: resolveUserTasks,
                },
                title: resolverFunctionForTitle
            },
            {
                path: 'tasks/new', component: NewTaskComponent,
                canDeactivate: [canLeavePage]
            }
        ],
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