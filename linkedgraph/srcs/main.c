/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:59:57 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 13:16:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int		main(void)
{
	LinkedGraph *myGraph;

	int number = 0;
	int vertaxID = 0;
	int fromVertaxID = 0;
	int toVertaxID = 0;
	int weigth = 0;
	int	startVertaxID = 0;
	

	printf("1 : Create UnDirected\n2 : Creatae Directed\n");
	scanf(" %d", &number);
	switch (number)
	{
		case 1:
			myGraph = createLinkedGraph(6);
			break;
		case 2:
			myGraph = createLinkedDirectedGraph(6);
			break;
		default:
			break;
	}
	while (1)
	{
		printf("1 : Add Vertax\n2 : Add Edge\n3 : Add Edge with weigth\n4 : Remove Vertax\n5 : Remove Edge\n6 : Delete Graph\n7: Display\n8: DFS\n9: BFS\n> ");
		scanf(" %d", &number);
		switch (number)
		{
			case 1:
				printf("insert vertaxID : ");
				scanf(" %d", &vertaxID);
				addVertexLG(myGraph, vertaxID);
				break;
			case 2:
				printf("from vertaxID, to vertaxID : ");
				scanf(" %d %d", &fromVertaxID, &toVertaxID);
				addEdgeLG(myGraph, fromVertaxID, toVertaxID);
				break;
			case 3:
				printf("from vertaxID, to vertaxID, weight: ");
				scanf(" %d %d %d", &fromVertaxID, &toVertaxID, &weigth);
				addEdgewithWeightLG(myGraph, fromVertaxID, toVertaxID, weigth);
				break;
			case 4:
				printf("insert vertaxID : ");
				scanf(" %d", &vertaxID);
				removeVertexLG(myGraph, vertaxID);
				break;
			case 5:
				printf("from vertaxID, to vertaxID : ");
				scanf(" %d %d", &fromVertaxID, &toVertaxID);
				removeEdgeLG(myGraph, fromVertaxID, toVertaxID);
				break;
			case 6:
				deleteLinkedGraph(myGraph);
				return (0);
				break;
			case 7:
				displayLinkedGraph(myGraph);
				break;
			case 8:
				printf("start index: ");
				scanf(" %d", &startVertaxID);
				checkDFSVisited(myGraph, startVertaxID);
				break;
			case 9:
				printf("start index: ");
				scanf(" %d", &startVertaxID);
				checkBFSVisited(myGraph, startVertaxID);
				break;
			default:
				break;
		}
		if (number == 6)
			break;
	}
	
	return (0);
}