#include <stdlib.h>
#include <stdio.h>
#include "tree_primitives.h"

int max(int a, int b)
{
	if(a>b){
		return a;
	}else{
		return b;
	}
}

tree_t cons_empty()
{
	tree_t tree=NULL;

	return tree;
}

tree_t cons(s_base_t v, tree_t fg, tree_t fd)
{
	tree_t tree=malloc(sizeof(s_node_t));
	tree->val=v;
	tree->fg=fg;
	tree->fd=fd;

	return tree;
}
/* Vrai si et seulement si l'arbre est vide */
int is_empty(tree_t a)
{
	return a==NULL;
}
/* Restitue la valeur du nœud racine, fonction aussi appelée Racine/root dans 
 * le sujet. 
 * L'arbre a ne doit pas etre  vide
*/
s_base_t value(tree_t a)
{
	return a->val;
}
/* Restitue le fils gauche 
 * L'arbre a ne doit pas etre  vide
 */
tree_t left(tree_t a)
{
	return a->fg;
}
/* Restitue le fils droit 
 * L'arbre a ne doit pas etre  vide
*/
tree_t right(tree_t a)
{
	return a->fd;
}
/* Remplace la valeur de la racine pa par new_value. Version légère avec simple
 * pointeur. 
 * L'arbre a ne doit pas etre  vide
*/
void change_value(tree_t pa, s_base_t new_value)
{
	pa->val=new_value;
}

/* Remplace le fils gauche de pa par new_left. Version légère avec simple
 * pointeur. 
 * L'arbre a ne doit pas etre  vide
*/
void change_left(tree_t pa, tree_t new_left)
{
	pa->fg=new_left;
}

/* Remplace le fils droit de pa par new_right. Version légère avec simple
 * pointeur. 
 * L'arbre a ne doit pas etre  vide
*/
void change_right(tree_t pa, tree_t new_right)
{
	pa->fd=new_right;
}

/* Libère la mémoire allouée pour l'arbre a */
void free_tree(tree_t a)
{
	if(!is_empty(a)){
		free_tree(left(a));
		free_tree(right(a));
		free(a);
	}
}
/* Affichage préfixe de l'arbre */
void prefix(tree_t a)
{
	if(!is_empty(a)){
		printf("%s\n", a->val.name);
		prefix(a->fg);
		prefix(a->fd);
	}
}
/* Affichage avec mise en forme "graphique" (indentation en fonction de la profondeur) */
void graphical_print(tree_t a, int depth)
{
	if(!is_empty(a)){
		printf("%*c", depth, ' ');
		printf("+--%s - %s\n", value(a).name,value(a).title);
		graphical_print(left(a),depth+1);
		graphical_print(right(a),depth+1);
	}
}
/* Affichage avec mise en forme "graphique" (indentation ET LIEN en fonction de la profondeur) */
void graphical_print_link(tree_t a, int depth, int trace[])
{
	if(!is_empty(a)){
		trace[depth]=depth;
		graphical_print_link(left(a),depth+1,trace);
		printf("%*c", depth, ' ');
		printf("+--%s - %s\n", value(a).name,value(a).title);
		graphical_print_link(right(a),depth+1,trace);
	}
}

/* Retourne la taille de l'arbre a */
int size(tree_t a)
{
	if(!is_empty(a)){
		return 1+size(left(a))+size(right(a));
	}else{
		return 0;
	}
}
/* Retourne la hauteur de l'arbre a */
int height(tree_t a)
{
	if(!is_empty(a)){
		return 1+max(height(left(a)),height(right(a)));
	}else{
		return 0;
	}
}
/* Teste l'existence de la donnée v dans l'arbre a */
int exists(tree_t a, s_base_t v)
{
	if(!is_empty(a)){
		if(value(a).name==v.name && value(a).title==v.title){
			return 1;
		}else{
			return exists(left(a),v) || exists(right(a),v);
		}
	}else{
		return 0;
	}
}