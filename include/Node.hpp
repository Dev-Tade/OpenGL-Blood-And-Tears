#ifndef NODE_H
#define NODE_H

class Node {
	public:
		Node();
		virtual void Draw();
		virtual void Update(double delta);
		virtual void OnLoad();
		virtual void Delete();
};

Node::Node() {
	OnLoad();
}

void Node::OnLoad() {

}

void Node::Draw() {

}

void Node::Update(double delta) {

}



void Node::Delete() {

}

#endif // !NODE_H
